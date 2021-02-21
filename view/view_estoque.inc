<?php

/**
 * View do Estoque
 *
 * @author Leonardo Alex Fusinato
 */
class ViewEstoque {
 
    public function __construct($aVeiculos, $bLoad = true) {
        if($bLoad) {
            echo '<section class="area-veiculos", id="main-section">';
            if(sizeof($aVeiculos) > 0){
                foreach ($aVeiculos as $oVeiculo) {
                    new Estrutura\Componentes\CardVeiculo($oVeiculo);
                }
            }
            echo '</section>';
        }
    }
    
    public function getHtml($aVeiculos) {
//        $sHtml = '<section class="area-veiculos", id="main-section">';
        $sHtml = '';
        if(sizeof($aVeiculos) > 0){
            foreach ($aVeiculos as $oVeiculo) {
                $oCard = new Estrutura\Componentes\CardVeiculo($oVeiculo);
                $sHtml .= $oCard->getHtml();
            }
        }
//        $sHtml .= '</section>';
        return $sHtml;
    }
    
}