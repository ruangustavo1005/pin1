<?php

require_once 'persistencia.inc';

/**
 * Persistência da Pessoa
 *
 * @author Leonardo Alex Fusinato
 */
class PersistenciaPessoa extends Persistencia {
    
    /**
     * Método para inserção de pessoas conforme modelo do parâmetro
     * 
     * @param  Cliente $oPessoa
     * @return Boolean
     */
    public function insertCliente(Cliente $oPessoa) {
        $oReq = $this->Query->prepare("
            INSERT INTO tbpessoa(pesgerente, peslogin, pessenha, pessalario, pesnome, pesdatanascimento, pesdataadmissao, pescpf, pesemail, pestelefone, dtype)
            VALUES (false, null, null, null, :nome, :data, null, :cpf, :email, :telefone, 'Cliente')"
        );
        $oReq->bindValue(':nome'    , $oPessoa->getNome());
        $oReq->bindValue(':data'    , $oPessoa->getDataNascimento());
        $oReq->bindValue(':cpf'     , $oPessoa->getCpf());
        $oReq->bindValue(':email'   , $oPessoa->getEmail());
        $oReq->bindValue(':telefone', $oPessoa->getTelefone());
        if($oReq->execute()) {
            return $this->getClienteFromCpf($oPessoa->getCpf());
        }
        return false;
    }
    
    /**
     * Retorna o cliente  a partir do CPF
     * 
     * @param String $sCpf
     * @return Cliente | false
     */
    public function getClienteFromCpf($sCpf) {
        $oReq = $this->Query->prepare("
            SELECT *
              FROM tbpessoa
             WHERE pescpf = :cpf
        ");
        $oReq->bindValue(':cpf', $sCpf);
        $oReq->execute();
        $oCliente = new Cliente();
        while ($oObject = $oReq->fetch(PDO::FETCH_OBJ)) {
            $oCliente->setCodigo($oObject->pescodigo);
            $oCliente->setCpf($sCpf);
            $oCliente->setDataNascimento($oObject->pesdatanascimento);
            $oCliente->setEmail($oObject->pesemail);
            $oCliente->setNome($oObject->pesnome);
            $oCliente->setTelefone($oObject->pestelefone);
        }
        return $oCliente->getCodigo() != null ? $oCliente : false;
    }
    
}