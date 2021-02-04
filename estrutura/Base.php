<?php

/**
 * Cria o menu da página
 */
function criaMenu() {
    ?>
    <div class='logo'>
        <a href="#"><img src="../images/logo.png" alt="Fusuan Motors"></a>
        <span>Fusuan Motors</span>
    </div>
    <nav>
        <ul>
            <li><a href="estoque.php">Estoque</a></li>
            <li><a href="contato.php">Contato</a></li>
        </ul>
    </nav>
    <?php
}

/**
 * Cria o card do veículo
 */
function criaCardVeiculo() {
    ?>
    <div class="card-veiculo">
        <div class="image-area">      
        </div>
        <button class="btn-detalhes">+ Detalhes</button> 
    </div>
    <?php
}