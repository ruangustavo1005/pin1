<?php

namespace Estrutura\Componentes;

/**
 * Componente de mensagem
 *
 * @author Leonardo Alex Fusinato
 */
abstract class Mensagem {
    
    const TIPO_SUCESSO = 1,
          TIPO_ERRO    = 2;
    
    protected $texto;
    private $tipo;
    
    public function __construct($tipo, $texto) {
        $this->tipo = $tipo;
        $this->texto = $texto;
    }
    
    public function getTexto() {
        return $this->texto;
    }
    
    /**
     * Retorna o HTML da mensagem
     */
    abstract public function getHtml();

}