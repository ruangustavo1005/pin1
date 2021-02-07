<?php

/**
 * Modelo da Pessoa
 *
 * @author Leonardo Alex Fusinato
 */
abstract class Pessoa {
 
    private $codigo;
    private $cpf;
    private $dataNascimento;
    private $nome;
    
    public function getCodigo() {
        return $this->codigo;
    }

    public function getCpf() {
        return $this->cpf;
    }

    public function getDataNascimento() {
        return $this->dataNascimento;
    }

    public function getNome() {
        return $this->nome;
    }

    public function setCodigo($codigo): void {
        $this->codigo = $codigo;
    }

    public function setCpf($cpf): void {
        $this->cpf = $cpf;
    }

    public function setDataNascimento($dataNascimento): void {
        $this->dataNascimento = $dataNascimento;
    }

    public function setNome($nome): void {
        $this->nome = $nome;
    }
    
}