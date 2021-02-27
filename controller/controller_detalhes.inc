<?php

require_once '../persistencia/persistencia_veiculo.inc';
require_once '../persistencia/persistencia_agendamento.inc';

/**
 * Controller dos Detalhes
 *
 * @author Leonardo Alex Fusinato
 */
class ControllerDetalhes {
    
    /** @var PersistenciaVeiculo */
    private $PersistenciaVeiculo;
    
    /** @var PersistenciaAgendamento */
    private $PersistenciaAgendamento;
    
    /** @var ViewDetalhes */
    private $View;
    
    public function getPersistenciaVeiculo(): PersistenciaVeiculo {
        if(!isset($this->PersistenciaVeiculo)) {
            $this->PersistenciaVeiculo = new PersistenciaVeiculo();
        }
        return $this->PersistenciaVeiculo;
    }
    
    public function getPersistenciaAgendamento(): PersistenciaAgendamento {
        if(!isset($this->PersistenciaAgendamento)) {
            $this->PersistenciaAgendamento = new PersistenciaAgendamento();
        }
        return $this->PersistenciaAgendamento;
    }
        
    public function getView(): ViewDetalhes {
        if(!isset($this->View)) {
            $this->View = new ViewDetalhes();
        }
        return $this->View;
    }
    
    /**
     * Retorna o HTML da página de detalhes
     * 
     * @return String
     */
    public function getHtmlFromView() {
        $oVeiculo = $this->getPersistenciaVeiculo()->getVeiculoFromPlaca($_POST['placa']);
        $this->getPersistenciaVeiculo()->getAllImagensFromVeiculo($oVeiculo);
        $aHorarios = $this->getPersistenciaAgendamento()->getHorariosSemana();
        return $this->getView()->getHtml($oVeiculo, $aHorarios);
    }
    
}