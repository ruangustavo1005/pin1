<?php

namespace Estrutura\Componentes;

require_once 'mensagem.inc';

/**
 * Componente de mensagem de erro
 *
 * @author Leonardo Alex Fusinato
 */
class MensagemErro extends Mensagem {
    
    public function __construct($texto) {
        parent::__construct(Mensagem::TIPO_SUCESSO, $texto);
    }
    
    /**
     * {@inheritdoc}
     */
    public function getHtml() {
        echo 
        '<div class="container-msg-fail" >
            <img class="info-icon-fail" src="../pin1/images/fail.png" />
            <span class="message-fail">'.$this->texto.'</span>
        </div>';
    }

}