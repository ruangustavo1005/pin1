<?php

/**
 * Modelo do Agendamento
 *
 * @author Leonardo Alex Fusinato
 */
class Agendamento {
    
    /** @var \Cliente */
    private $Cliente;
    
    /** @var \Veiculo */
    private $Veiculo;
    
    private $codigo;
    private $dataHora;
    private $situacao;

    public function getCliente(): \Cliente {
        if(!isset($this->Cliente)) {
            $this->Cliente = new \Cliente();
        }
        return $this->Cliente;
    }

    public function getVeiculo(): \Veiculo {
        if(!isset($this->Veiculo)) {
            $this->Veiculo = new \Veiculo();
        }
        return $this->Veiculo;
    }

    public function getCodigo() {
        return $this->codigo;
    }

    public function getDataHora() {
        return $this->dataHora;
    }

    public function getSituacao() {
        return $this->situacao;
    }

    public function setCliente(\Cliente $Cliente): void {
        $this->Cliente = $Cliente;
    }

    public function setVeiculo(\Veiculo $Veiculo): void {
        $this->Veiculo = $Veiculo;
    }

    public function setCodigo($codigo): void {
        $this->codigo = $codigo;
    }

    public function setDataHora($dataHora): void {
        $this->dataHora = $dataHora;
    }

    public function setSituacao($situacao): void {
        $this->situacao = $situacao;
    }
    
}