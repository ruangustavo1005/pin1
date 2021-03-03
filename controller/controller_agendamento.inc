<?php

require_once '../persistencia/persistencia_pessoa.inc';
require_once '../model/cliente.php';

/**
 * Controller do Agendamento
 *
 * @author Leonardo Alex Fusinato
 */
class ControllerAgendamento {
    
    /** @var PersistenciaPessoa */
    private $PersistenciaPessoa;
    
    public function getPersistenciaPessoa(): PersistenciaPessoa {
        if(!isset($this->PersistenciaPessoa)) {
            $this->PersistenciaPessoa = new PersistenciaPessoa();
        }
        return $this->PersistenciaPessoa;
    }
        
    /**
     * Realiza o processo do agendamento do cliente com o veículo
     */
    public function realizaAgendamento() {
        $this->insereCliente();
    }
    
    /**
     * Insere a pessoa (cliente) caso não exista
     */
    private function insereCliente() {
        $oCliente = new Cliente();
        $oCliente->setCpf($_POST['cpf']);
        $oCliente->setDataNascimento($_POST['nascimento']);
        $oCliente->setEmail($_POST['email']);
        $oCliente->setNome($_POST['nome']);
        $oCliente->setTelefone($_POST['telefone']);
        $this->getPersistenciaPessoa()->insertPessoa($oCliente);
        echo 'sim';
    }
    
}