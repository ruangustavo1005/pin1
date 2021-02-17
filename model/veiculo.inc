<?php

require_once 'imagem_carro.inc';

/**
 * Modelo do Veículo
 *
 * @author Leonardo Alex Fusinato
 */
class Veiculo {
    
    /** @var ImagemCarro[] */
    private $Imagens;
    
    /** @var \Modelo */
    private $Modelo;
    
    private $placa;
    private $anoFabricacao;
    private $cor;
    private $observacao;
    private $preco;
    private $quilometragem;
    private $situacao;
    
    public function __construct(\Modelo $Modelo = null, $placa = null, $anoFabricacao = null, $cor = null, $observacao = null, $preco = null, $quilometragem = null, $situacao = null) {
        $this->Imagens = [];
        $this->Modelo = $Modelo;
        $this->placa = $placa;
        $this->anoFabricacao = $anoFabricacao;
        $this->cor = $cor;
        $this->observacao = $observacao;
        $this->preco = $preco;
        $this->quilometragem = $quilometragem;
        $this->situacao = $situacao;
    }
    
    public function getModelo(): \Modelo {
        if(!isset($this->Modelo)) {
            $this->Modelo =  new Modelo();
        }
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
    
    public function getSituacao() {
        return $this->situacao;
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
    
    public function setSituacao($situacao): void {
        $this->situacao = $situacao;
    }
    
    public function getImagens() {
        return $this->Imagens;
    }
    
    /**
     * Adiciona uma nova imagem ao veiculo
     */
    public function newImagem($iCodigo, $sConteudo) {
        $this->Imagens[] = new ImagemCarro($this, $iCodigo, $sConteudo); 
    }
    
    /**
     * Limpa o array de imagens do veículo
     */
    public function resetImagens() {
        $this->Imagens = [];
    }

}