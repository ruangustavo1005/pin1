<?php

/**
 * View de Detalhes do Veículo
 *
 * @author Leonardo Alex Fusinato
 */
class ViewDetalhes {

    public function __construct(\Veiculo $oVeiculo) {
        ?>
        <div class="main">
            <section class="vehicle-area-images">
                <div class="vehicle-image-info">
                    <div id="slider">
                        <img class="img_slide selected" src="../images/hb20.jpg">
                        <img class="img_slide" src="../images/monki-flip.jpg">
                        <img class="img_slide" src="../images/car.png">
                    </div>
                </div>
                <button class="btn_imgs prev-btn" onclick="prevImage()"><</button>
                <button class="btn_imgs next-btn" onclick="nextImage()">></button>
                <h3><?= $oVeiculo->getModelo()->getMarca()->getNome() . ' ' . $oVeiculo->getModelo()->getNome() . ' ' . $oVeiculo->getAnoFabricacao() ?></h3>
            </section>
            <section class="vehicle-info-area">
                <?php $this->criaTabelaHorarios() ?>

            </section>
        </div>
        <?php
    }

    private function criaTabelaHorarios() {
        ?>
        <table class="tb-horarios" border="1px solid black">
            <tr>
                <th></th><th>Domingo</th><th>Segunda</th><th>Terça</th><th>Quarta</th><th>Quinta</th><th>Sexta</th><th>Sábado</th>
            </tr>
            <tr>
                <td>08:00</td>
            </tr>
        </table>
        <?php
    }

}
