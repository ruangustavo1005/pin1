<?php

/**
 * View de Detalhes do Veículo
 *
 * @author Leonardo Alex Fusinato
 */
class ViewDetalhes {
    
    public function getHtml($oVeiculo) {
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
        $sHtml .= $this->criaTabelaHorarios();
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
                            <td class="value">'.$oVeiculo->getObservacao().'</td>
                        </tr>
                    </table>
                </fieldset>';
        return $sHtml;
    }

    private function criaTabelaHorarios() {
       $sHtml ='
        <fieldset class="fieldset">
            <legend>Agende sua Visita</legend>
            <table class="tb-horarios" border="1px solid black">
                <tr>
                    <th></th><th>Domingo</th><th>Segunda</th><th>Terça</th><th>Quarta</th><th>Quinta</th><th>Sexta</th><th>Sábado</th>
                </tr>
                <tr>
                    <td>08:00</td>
                </tr>
            </table>
        </fieldset>
        ';
       return $sHtml;
    }

}
