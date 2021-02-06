<?php

namespace Estrutura;

/**
 * Classe para a Criação de Cards de Veículos
 *
 * @author Leonardo Alex Fusinato
 */
class CardVeiculo {

    public function __construct(\Veiculo $oVeiculo) {
        ?>
            <div class="card-veiculo">
                <div class="image-area"> 
                    <img class="vehicle-image" src="../images/hb20.jpg"/>
                </div>
                <div class="info">
                    <span><?= $oVeiculo->getMarca() . ' ' . $oVeiculo->getModelo() . ' ' . $oVeiculo->getAno() ?></span>
                </div>
                <button class="btn-detalhes open-modal" onclick="abrirModal()">Agendar Visita</button> 
            </div>
            <div class="bg-modal" id="modal">
                <div class="modal">
                    <span class="close" onclick="fecharModal()">&times;</span>
                </div>
            </div>
        <?php
    }

}