<?php

/**
 * Persistência do Veículo
 *
 * @author Leonardo Alex Fusinato
 */
class PersistenciaVeiculo extends \Persistencia {
    
    /**
     * Retorna todos os veículos disponíveis em estoque
     */
    public function getAllVeiculosDisponiveis() {
        $sSql = "
            SELECT *
             FROM tbveiculo
             LEFT JOIN tbfotoveiculo
               ON tbfotoveiculo.veiplaca = tbveiculo.veiplaca
            WHERE tbveiculo.veisituacao = 1
        ";
        /* @var $oQuery \Query*/
        $oQuery = $this->Query;
        
    }
    
}