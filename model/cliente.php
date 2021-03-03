<?php

require_once 'pessoa.inc';

/**
 * Modelo do Cliente
 *
 * @author Leonardo Alex Fusinato
 */
class Cliente extends \Pessoa {
    
    private $email;
    private $telefone;
    
    public function getEmail() {
        return $this->email;
    }

    public function getTelefone() {
        return $this->telefone;
    }

    public function setEmail($email): void {
        $this->email = $email;
    }

    public function setTelefone($telefone): void {
        $this->telefone = $telefone;
    }
    
}