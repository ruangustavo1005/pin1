<?php

/**
 * Controlador do Estoque de Veículos
 *
 * @author Leonardo Alex Fusinato
 */
class ControllerEstoque {
    
    /** @var Veiculos[] */
    private $Veiculos;
    
    /** @var ViewEstoque */
    private $View;
    
    public function __construct() {
        $this->Veiculos = $this->getAllVeiculosDisponiveis();
        $this->View = new ViewEstoque($this->Veiculos);
    }
    
    /**
     * Função responsável por trazer todos os veículos disponíveis que irão aparecer na página de estoques do site
     */
    private function getAllVeiculosDisponiveis() {
        $oPers = new PersistenciaVeiculo();
        $aVeiculos = $oPers->getAllVeiculosDisponiveis();
        foreach ($aVeiculos as $oVeiculo) {
            $oPers->getAllImagensFromVeiculo($oVeiculo);
        }
        return $aVeiculos;
    }
    
}