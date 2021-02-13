<?php

namespace Estrutura\Componentes;

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
                    <?php
                        if(sizeof($oVeiculo->getImagens()) > 0) {
                            echo "<img class=\"vehicle-image\" src='data:image/jpeg;base64, {$oVeiculo->getImagens()[0]->getConteudo()}'/>";
                        }
                    ?>
                </div>
                <div class="info">
                    <span><?= $oVeiculo->getModelo()->getMarca()->getNome() . ' ' . $oVeiculo->getModelo()->getNome() . ' ' . $oVeiculo->getAnoFabricacao() ?></span><br>
                    <span><?= 'R$'.$oVeiculo->getPreco() ?></span>
                </div>
                <button class="btn-detalhes open-modal" onclick="abrirModal()">Agendar Visita</button> 
            </div>
            <div class="bg-modal" id="modal">
                <div class="modal">
                    <span class="close" onclick="fecharModal()">&times;</span><br>
                    <?php
                        new \ViewDetalhes($oVeiculo);
                    ?>
                </div>
            </div>
        <?php
    }

}