<?php

/**
 * Controlador do Estoque de Veículos
 *
 * @author Leonardo Alex Fusinato
 */
class ControllerEstoque {
    
    /** @var Veiculos[] */
    private $Veiculos;
    
    public function __construct() {
        $this->Veiculos = $this->getAllVeiculosDisponiveis();
    }
    
    /**
     * Função responsável por trazer todos os veículos disponíveis que irão aparecer na página de estoques do site
     */
    private function getAllVeiculosDisponiveis() {
        
    }
    
}