<?php

/**
 * View do Estoque
 *
 * @author Leonardo Alex Fusinato
 */
class ViewEstoque {
 
    public function __construct($aVeiculos) {
        echo '<section class="area-veiculos", id="main-section">';
        if(sizeof($aVeiculos) > 0){
            foreach ($aVeiculos as $oVeiculo) {
                new Estrutura\Componentes\CardVeiculo($oVeiculo);
            }
        }
        echo '</section>';
    }
    
}