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
    
    /** @var PersistenciaVeiculo */
    private $PersistenciaVeiculo;
    
    public function getPersistenciaVeiculo(): PersistenciaVeiculo {
        if(!isset($this->PersistenciaVeiculo)) {
            $this->PersistenciaVeiculo = new PersistenciaVeiculo();
        }
        return $this->PersistenciaVeiculo;
    }
        
    public function __construct() {
        $this->Veiculos = $this->getAllVeiculosDisponiveis();
        $this->View = new ViewEstoque($this->Veiculos, false);
    }
    
    public function getHtml() {
        return $this->View->getHtml($this->Veiculos);
    }
    
    /**
     * Função responsável por trazer todos os veículos disponíveis que irão aparecer na página de estoques do site
     */
    private function getAllVeiculosDisponiveis() {
        $aVeiculos = $this->getPersistenciaVeiculo()->getAllVeiculosDisponiveis();
        foreach ($aVeiculos as $oVeiculo) {
            $this->getPersistenciaVeiculo()->getAllImagensFromVeiculo($oVeiculo);
        }
        return $aVeiculos;
    }
    
    /**
     * Retorna os veículos conforme o filtro selecionado pelo usuário
     */
    public function getHtmlFromViewFiltrada() {
        $sFilter = $_POST['filter'];
        $sFilterValue = $_POST['filterValue'];
        
        if($sFilter && $sFilterValue) {
            return $this->getVeiculosFiltrados($sFilter, $sFilterValue);
        }
    }
    
    /**
     * Retorna os veículos filtrados
     * 
     * @param String $sFilter Filtro selecionado
     * @param String $sFilterValue Valor do Filtro
     */
    private function getVeiculosFiltrados($sFilter, $sFilterValue) {
        if($sFilter == 'marca') {
            $aVeiculos = $this->getPersistenciaVeiculo()->getVeiculosFromMarca($sFilterValue);
        } else {
            
        }
        foreach ($aVeiculos as $oVeiculo) {
            $this->getPersistenciaVeiculo()->getAllImagensFromVeiculo($oVeiculo);
        }
        $oView = new ViewEstoque($aVeiculos, false);
        return $oView->getHtml($aVeiculos);
    }
    
}