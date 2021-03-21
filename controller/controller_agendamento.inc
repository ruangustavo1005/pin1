<?php

require_once '../persistencia/persistencia_pessoa.inc';
require_once '../persistencia/persistencia_agendamento.inc';
require_once '../persistencia/persistencia_veiculo.inc';
require_once '../model/cliente.php';
require_once '../model/agendamento.inc';
require_once '../estrutura/componentes/mensagem.inc';
require_once '../estrutura/componentes/mensagem_sucesso.inc';
require_once '../estrutura/componentes/mensagem_erro.inc';

/**
 * Controller do Agendamento
 *
 * @author Leonardo Alex Fusinato
 */
class ControllerAgendamento {
    
    /** @var PersistenciaPessoa */
    private $PersistenciaPessoa;
    
    /** @var PersistenciaAgendamento */
    private $PersistenciaAgendamento;
    
    /** @var PersistenciaVeiculo */
    private $PersistenciaVeiculo;
    
    public function getPersistenciaPessoa(): PersistenciaPessoa {
        if(!isset($this->PersistenciaPessoa)) {
            $this->PersistenciaPessoa = new PersistenciaPessoa();
        }
        return $this->PersistenciaPessoa;
    }
    
    public function getPersistenciaAgendamento(): PersistenciaAgendamento {
        if(!isset($this->PersistenciaAgendamento)) {
            $this->PersistenciaAgendamento = new PersistenciaAgendamento();
        }
        return $this->PersistenciaAgendamento;
    }

    public function getPeristenciaVeiculo(): PersistenciaVeiculo {
        if(!isset($this->PersistenciaVeiculo)) {
            $this->PersistenciaVeiculo = new PersistenciaVeiculo();
        }
        return $this->PersistenciaVeiculo;
    }
            
    /**
     * Realiza o processo do agendamento do cliente com o veículo
     */
    public function realizaAgendamento() {
        if(!$oCliente = $this->getPersistenciaPessoa()->getClienteFromCpf($_POST['cpf'])){
            $oCliente = $this->insereCliente();
        }
        if($oCliente) {
            $this->insereAgendamento($oCliente);
        } else {
            $this->mensagemErro();
        }
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
        return $this->getPersistenciaPessoa()->insertCliente($oCliente);
    }
    
    /**
     * Insere o agendamento do veículo
     */
    private function insereAgendamento($oCliente) {
        $oAgendamento = new Agendamento();
        $oAgendamento->setCliente($oCliente);
        $oAgendamento->setDataHora($_POST['horario']);
        $oAgendamento->setSituacao(PersistenciaAgendamento::SITUACAO_ANALISE);
        $oAgendamento->setVeiculo($this->getPeristenciaVeiculo()->getVeiculoFromPlaca($_POST['placa']));
        try {
            $this->getPersistenciaAgendamento()->insereAgendamento($oAgendamento);
            $this->mensagemSucesso();
        } catch (Exception $ex) {
            $this->mensagemErro();
        }
    }
    
    /**
     * Retorna uma mensagem de sucesso
     * 
     * @return String
     */
    private function mensagemSucesso() {
        $oMsg = new Estrutura\Componentes\MensagemSucesso('Agendamento inserido com sucesso!');
        return $oMsg->getHtml();
    }
    
    /**
     * Retorna uma mensagem de erro
     * 
     * @return String
     */
    private function mensagemErro() {
        $oMsg = new Estrutura\Componentes\MensagemErro('Erro ao inserir o agendamento');
        return $oMsg->getHtml();
    }
    
}