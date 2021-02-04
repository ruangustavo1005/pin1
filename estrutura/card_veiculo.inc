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
                <table class="vehicle-info">
                    <tr>
                        <td class="label"><span>Marca:</span></td>
                        <td><span><?= $oVeiculo->getMarca() ?></span></td>
                    </tr>
                    <tr>
                        <td class="label"><span>Modelo:</span></td>
                        <td><span><?= $oVeiculo->getModelo() ?></span></td>
                    </tr>
                    <tr>
                        <td class="label"><span>Ano:</span></td>
                        <td><span><?= $oVeiculo->getAno() ?></span></td>
                    </tr>
                </table>
            </div>
            <button class="btn-detalhes">+ Detalhes</button> 
        </div>
        <?php
    }

}
