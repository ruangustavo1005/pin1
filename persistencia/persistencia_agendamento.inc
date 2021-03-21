<?php

require_once 'persistencia.inc';
require_once '../model/horario_agendamento.inc';
require_once '../estrutura/date_util.inc';

/**
 * Persistência do Agendamento
 *
 * @author Leonardo Alex Fusinato
 */
class PersistenciaAgendamento extends Persistencia {
    
    const SITUACAO_ANALISE = 1;
    
    const ATRIBUTO_HORARIO = [
        1 => '08:00',
        2 => '09:00',
        3 => '10:00',
        4 => '11:00',
        5 => '13:00',
        6 => '14:00',
        7 => '15:00',
        8 => '16:00',
        9 => '17:00'
    ];
    
    /**
     * Retorna a disponibilidade dos horários de agendamentos da semana atual
     * 
     * @return HorarioAgendamento[]
     */
    public function getHorariosSemana() {
        $aDatas = DateUtil::getDiasSemana();
        $sSql = "
               select is_horario_disponivel((dia||' '||hora1)::timestamp) as \"08:00\",
                      is_horario_disponivel((dia||' '||hora2)::timestamp) as \"09:00\",
                      is_horario_disponivel((dia||' '||hora3)::timestamp) as \"10:00\",
                      is_horario_disponivel((dia||' '||hora4)::timestamp) as \"11:00\",
                      is_horario_disponivel((dia||' '||hora5)::timestamp) as \"13:00\",
                      is_horario_disponivel((dia||' '||hora6)::timestamp) as \"14:00\",
                      is_horario_disponivel((dia||' '||hora7)::timestamp) as \"15:00\", 
                      is_horario_disponivel((dia||' '||hora8)::timestamp) as \"16:00\",
                      is_horario_disponivel((dia||' '||hora9)::timestamp) as \"17:00\"
                from (select '$aDatas[0]' as dia
                      union all
                      select '$aDatas[1]' as dia
                      union all
                      select '$aDatas[2]' as dia
                      union all
                      select '$aDatas[3]' as dia
                      union all
                      select '$aDatas[4]' as dia) as dias
                 join lateral (select '08:00' as hora1,
                                      '09:00' as hora2,
                                      '10:00' as hora3,
                                      '11:00' as hora4,
                                      '13:00' as hora5,
                                      '14:00' as hora6,
                                      '15:00' as hora7,
                                      '16:00' as hora8,
                                      '17:00' as hora9) as horas
                   on true
        ";
        $aHorarios = [];
        $oSql = $this->Query->query($sSql);
        foreach($oSql->fetchAll(PDO::FETCH_OBJ) as $key => $oObject) {
            $oHorario = new HorarioAgendamento();
            $oHorario->setDia($aDatas[$key]);
            $oHorario->setHora1($oObject->{'08:00'} == 1 ? 'Disponível' : 'Cheio');
            $oHorario->setHora2($oObject->{'09:00'} == 1 ? 'Disponível' : 'Cheio');
            $oHorario->setHora3($oObject->{'10:00'} == 1 ? 'Disponível' : 'Cheio');
            $oHorario->setHora4($oObject->{'11:00'} == 1 ? 'Disponível' : 'Cheio');
            $oHorario->setHora5($oObject->{'13:00'} == 1 ? 'Disponível' : 'Cheio');
            $oHorario->setHora6($oObject->{'14:00'} == 1 ? 'Disponível' : 'Cheio');
            $oHorario->setHora7($oObject->{'15:00'} == 1 ? 'Disponível' : 'Cheio');
            $oHorario->setHora8($oObject->{'16:00'} == 1 ? 'Disponível' : 'Cheio');
            $oHorario->setHora9($oObject->{'17:00'} == 1 ? 'Disponível' : 'Cheio');
            $aHorarios[] = $oHorario;
        }
        return $aHorarios;
    }
    
    
    /**
     * Insere um novo agendamento com base no modelo passado por parâmetro
     * 
     * @param  Agendamento $oAgendamento
     * @return Boolean
     */
    public function insereAgendamento(Agendamento $oAgendamento) {
        $oReq = $this->Query->prepare("
            INSERT INTO tbagendamento(agesituacao, agedatahora, pescodigofuncionario, pescodigocliente, veiplaca)
            VALUES (:situacao, :dataHora, null, :codigoCliente, :placa);
        ");
        $oReq->bindValue(':situacao', $oAgendamento->getSituacao());
        $oReq->bindValue(':dataHora', $oAgendamento->getDataHora());
        $oReq->bindValue(':codigoCliente', $oAgendamento->getCliente()->getCodigo());
        $oReq->bindValue(':placa', $oAgendamento->getVeiculo()->getPlaca());
        return $oReq->execute();
    }
    
}