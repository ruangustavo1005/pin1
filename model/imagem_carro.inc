<?php

/**
 * Modelo da Imagem do Veículo
 *
 * @author Leonardo Alex Fusinato
 */
class ImagemCarro {
 
    /** @var \Veiculo */
    private $Veiculo;
    
    private $codigo;
    private $conteudo;
    
    public function getVeiculo(): \Veiculo {
        return $this->Veiculo;
    }

    public function getCodigo() {
        return $this->codigo;
    }

    public function getConteudo() {
        return $this->conteudo;
    }

    public function setVeiculo(\Veiculo $Veiculo): void {
        $this->Veiculo = $Veiculo;
    }

    public function setCodigo($codigo): void {
        $this->codigo = $codigo;
    }

    public function setConteudo($conteudo): void {
        $this->conteudo = $conteudo;
    }
    
}