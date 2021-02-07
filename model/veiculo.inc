<?php

/**
 * Modelo do veículo
 *
 * @author Leonardo Alex Fusinato
 */
class Veiculo {
    
    /** @var \Modelo */
    private $Modelo;
    
    private $placa;
    private $anoFabricacao;
    private $cor;
    private $observacao;
    private $preco;
    private $quilometragem;
    
    public function __construct(\Modelo $Modelo = null, $placa = null, $anoFabricacao = null, $cor = null, $observacao = null, $preco = null, $quilometragem = null) {
        $this->Modelo = $Modelo;
        $this->placa = $placa;
        $this->anoFabricacao = $anoFabricacao;
        $this->cor = $cor;
        $this->observacao = $observacao;
        $this->preco = $preco;
        $this->quilometragem = $quilometragem;
    }
    
    public function getModelo(): \Modelo {
        return $this->Modelo;
    }

    public function getPlaca() {
        return $this->placa;
    }

    public function getAnoFabricacao() {
        return $this->anoFabricacao;
    }

    public function getCor() {
        return $this->cor;
    }

    public function getObservacao() {
        return $this->observacao;
    }

    public function getPreco() {
        return $this->preco;
    }

    public function getQuilometragem() {
        return $this->quilometragem;
    }

    public function setModelo(\Modelo $Modelo): void {
        $this->Modelo = $Modelo;
    }

    public function setPlaca($placa): void {
        $this->placa = $placa;
    }

    public function setAnoFabricacao($anoFabricacao): void {
        $this->anoFabricacao = $anoFabricacao;
    }

    public function setCor($cor): void {
        $this->cor = $cor;
    }

    public function setObservacao($observacao): void {
        $this->observacao = $observacao;
    }

    public function setPreco($preco): void {
        $this->preco = $preco;
    }

    public function setQuilometragem($quilometragem): void {
        $this->quilometragem = $quilometragem;
    }

}