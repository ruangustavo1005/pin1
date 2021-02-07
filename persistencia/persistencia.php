<?php

namespace \Persistencia;

/**
 * Persistência Padrão
 *
 * @author Leonardo Alex Fusinato
 */
class Persistencia {
    
    /** @var \Query */
    protected $Query;
    
    public function __construct() {
        $this->Query = new \Query();
    }
    
}