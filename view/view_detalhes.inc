<?php

/**
 * View de Detalhes do Veículo
 *
 * @author Leonardo Alex Fusinato
 */
class ViewDetalhes {
    
    public function getHtml($oVeiculo, $aHorarios) {
        $sHtml = '
        <span class="close" onclick="closeDetails()">&times;</span>
        <div class="main">
            <section class="vehicle-area-images">
                <div class="vehicle-image-info">
                    <div id="slider">';
        for($i = 0; $i < sizeof($oVeiculo->getImagens()); $i++) {
            if($i == 0) {
                $sHtml .= "<img class=\"img_slide selected\" src=\"data:image/jpeg;base64, {$oVeiculo->getImagens()[$i]->getConteudo()}\"/>";
            } else {
                $sHtml .= "<img class=\"img_slide\" src=\"data:image/jpeg;base64, {$oVeiculo->getImagens()[$i]->getConteudo()}\"/>";
            }
        }
        $sHtml .='  </div>
                </div>
                <button class="btn_imgs prev-btn" onclick="prevImage()"><</button>
                <button class="btn_imgs next-btn" onclick="nextImage()">></button>
                <h3>'.$oVeiculo->getModelo()->getMarca()->getNome() . ' ' . $oVeiculo->getModelo()->getNome() . ' ' . $oVeiculo->getAnoFabricacao().' </h3>
                <h3>R$ '. $oVeiculo->getPreco().'</h3>
            </section>
            <section class="vehicle-info-area">';
        $sHtml .= $this->criaTabelaDetalhes($oVeiculo);
        $sHtml .= $this->criaTabelaHorarios($aHorarios);
        $sHtml .= $this->criaFormAgendamento();
        $sHtml .= ' </section>
              </div>';
            
        return $sHtml;
    }
    
    /**
     * Cria a tabela de informações do veículo
     * 
     * @param type $oVeiculo
     */
    private function criaTabelaDetalhes($oVeiculo) {
        $sHtml = '<fieldset class="fieldset">
                    <legend>Detalhes</legend>
                    <table class="details-table">
                        <tr style="display:none">
                            <td class="label">Placa:</td>
                            <td class="value" id="placa">'.$oVeiculo->getPlaca().'</td>
                        </tr>
                        <tr>
                            <td class="label">Marca:</td>
                            <td class="value">'.$oVeiculo->getModelo()->getMarca()->getNome().'</td>
                        </tr>
                        <tr>
                            <td class="label">Modelo:</td>
                            <td class="value">'.$oVeiculo->getModelo()->getNome().'</td>
                        </tr>
                        <tr>
                            <td class="label">Ano de Fabricação:</td>
                            <td class="value">'.$oVeiculo->getAnoFabricacao().'</td>
                        </tr>
                        <tr>
                            <td class="label">Cor:</td>
                            <td class="value">'.$oVeiculo->getCor().'</td>
                        </tr>
                        <tr>
                            <td class="label">Quilometragem:</td>
                            <td class="value">'.$oVeiculo->getQuilometragem().'Km</td>
                        </tr>
                        <tr>
                            <td class="label">Observações:</td>
                            <td class="value">
                                <ul class"list-obs" style="padding-left: 25px;">';
        foreach(explode(';', $oVeiculo->getObservacao()) as $sObs) {
            $sHtml .= '<li>'.$sObs.'</li>';
        }
        $sHtml .='              </ul>
                            </td>
                        </tr>
                    </table>
                </fieldset>';
        return $sHtml;
    }

    private function criaTabelaHorarios($aHorarios) {
       $sHtml = "
        <fieldset class=\"fieldset\">
            <legend>Agende sua visita</legend>
            <table class=\"tb-horarios\" border=\"1px solid black\">
                <tr>
                    <th></th><th>Segunda</th><th>Terça</th><th>Quarta</th><th>Quinta</th><th>Sexta</th>
                </tr>";
       for($i = 1; $i <= 9; $i++) {
            $sMethod = "getHora$i";
            $sHtml .= '<tr><td>'.PersistenciaAgendamento::ATRIBUTO_HORARIO[$i].'</td>';
            for ($j = 0; $j <= 4; $j++) {
                $sSituacao = $aHorarios[$j]->$sMethod();
                $sClass = $sSituacao == 'Disponível' ? 'selecionavel' : 'n-selecionavel';
                $sHtml .= "<td id=\"{$aHorarios[$j]->getDia()}_".PersistenciaAgendamento::ATRIBUTO_HORARIO[$i]."}\"
                            class=\"$sClass\"
                            onclick=\"selectHorario(this)\">$sSituacao</td>";
            }
            $sHtml .= "</tr>";
       }
       $sHtml .= "</table>
        </fieldset>";
            
        return $sHtml;
    }
    
    private function criaFormAgendamento() {
        $sHtml = '
            <div class="container">
            <fieldset class="fieldset agendamento">
                <table class="details-table">
                    <tr>
                        <td class="label">Nome:</td>
                        <td class="value"><input id="nome" type="text"></td>
                    </tr>
                    <tr>
                        <td class="label">CPF:</td>
                        <td class="value"><input id="cpf" type="text"></td>
                    </tr>
                    <tr>
                        <td class="label">Data de Nascimento:</td>
                        <td class="value"><input id="nascimento" type="date"></td>
                    </tr>
                    <tr>
                        <td class="label">Email:</td>
                        <td class="value"><input id="email" type="email"></td>
                    </tr>
                    <tr>
                        <td class="label">Telefone:</td>
                        <td class="value"><input id="telefone" type="text"></td>
                    </tr>
                </table>
                <button class="agendamento-btn" onClick="realizaAgendamento()">Agendar</button>
            </fieldset>
            </div>
        ';
        return $sHtml;
    }

}
