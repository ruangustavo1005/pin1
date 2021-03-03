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
     */
    public function insertPessoa(Cliente $oPessoa) {
        $oReq = $this->Query->prepare("
            INSERT INTO tbpessoa(pescodigo, pesgerente, peslogin, pessenha, pessalario, pesnome, pesdatanascimento, pesdataadmissao, pescpf, pesemail, pestelefone, dtype)
            VALUES (:codigo, false, null, null, null, :nome, :data, null, :cpf, :email, :telefone, 'Cliente')"
        );
        $oReq->bindValue(':codigo'  , $oPessoa->getCodigo());
        $oReq->bindValue(':nome'    , $oPessoa->getNome());
        $oReq->bindValue(':data'    , $oPessoa->getDataNascimento());
        $oReq->bindValue(':cpf'     , $oPessoa->getCpf());
        $oReq->bindValue(':email'   , $oPessoa->getEmail());
        $oReq->bindValue(':telefone', $oPessoa->getTelefone());
        $oReq->execute();
    }
    
}