<?php

/**
 * Modelo da Marca
 *
 * @author Leonardo Alex Fusinato
 */
class Marca {
    
    private $codigo;
    private $nome;
    
    public function __construct($codigo = null, $nome = null) {
        $this->codigo = $codigo;
        $this->nome = $nome;
    }
    
    public function getCodigo() {
        return $this->codigo;
    }

    public function getNome() {
        return $this->nome;
    }

    public function setCodigo($codigo): void {
        $this->codigo = $codigo;
    }

    public function setNome($nome): void {
        $this->nome = $nome;
    }
    
}