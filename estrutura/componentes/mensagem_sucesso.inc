<?php

namespace Estrutura\Componentes;

require_once 'mensagem.inc';

/**
 * Componente de mensagem de sucesso
 *
 * @author Leonardo Alex Fusinato
 */
class MensagemSucesso extends Mensagem {
    
    public function __construct($texto) {
        parent::__construct(Mensagem::TIPO_SUCESSO, $texto);
    }
    
    /**
     * {@inheritdoc}
     */
    public function getHtml() {
        echo 
        '<div class="container-msg-success" >
            <img class="info-icon-success" src="../pin1/images/success.png" />
            <span class="message-success">'.$this->texto.'</span>
        </div>';
    }

}