<?php


/**
 * Modelo do Modelo do Veículo
 *
 * @author Leonardo Alex Fusinato
 */
class Modelo {
 
    /** @var \Marca */
    private $Marca;
    
    private $codigo;
    private $ano;
    private $nome;
    
    public function __construct(\Marca $Marca = null, $codigo = null, $ano = null, $nome = null) {
        $this->Marca = $Marca;
        $this->codigo = $codigo;
        $this->ano = $ano;
        $this->nome = $nome;
    }
    
    public function getMarca(): \Marca {
        if(!isset($this->Marca)) {
            $this->Marca = new \Marca();
        }
        return $this->Marca;
    }

    public function getCodigo() {
        return $this->codigo;
    }

    public function getAno() {
        return $this->ano;
    }

    public function getNome() {
        return $this->nome;
    }

    public function setMarca(\Marca $Marca): void {
        $this->Marca = $Marca;
    }

    public function setCodigo($codigo): void {
        $this->codigo = $codigo;
    }

    public function setAno($ano): void {
        $this->ano = $ano;
    }

    public function setNome($nome): void {
        $this->nome = $nome;
    }
    
}