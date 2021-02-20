<?php

/**
 * View da Pesquisa
 *
 * @author Leonardo Alex Fusinato
 */
class ViewSearch {
 
    /**
     * Retorna o HTML com as opções de pesquisa
     * 
     * @param Marca[] $aMarcas
     * @param Modelo[] $aModelos
     */
    public function getCamposPesquisa($aMarcas, $aModelos) {
        echo '<select id="option" onChange="alterOption()">';
        echo    '<option value="marca" selected>Marca </option>';
        echo    '<option value="modelo">Modelo</option>';
        echo '</select>';
        echo '<select id="marca" onChange="alterOption()" style="display:none">';
        foreach ($aMarcas as $oMarca) {
//            $sSelected = $oMarca->getCodigo() == $aMarcas[0]->getCodigo() ? 'selected' : '';
            echo '<option value="'.$oMarca->getCodigo().'">'.$oMarca->getNome().'</option>';
        }
        echo '</select>';
        echo '<select id="modelo" onChange="alterOption()" style="display:none">';
        foreach ($aModelos as $oModelo) {
            echo '<option value="'.$oModelo->getCodigo().'">'.$oModelo->getNome().'</option>';
        }
        echo '</select>';
        
        echo '<button style="cursor:pointer">Buscar</button>';
    }
    
}