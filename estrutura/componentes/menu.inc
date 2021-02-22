<?php

namespace Estrutura\Componentes;

/**
 * Classe do Menu
 *
 * @author Leonardo Alex Fusinato
 */
class Menu {

    public function __construct() {
        ?>
        <div class='logo'>
            <a href="index.php"><img src="./images/logoo.jpeg" alt="Fusuan Motors"></a>
        </div>
        <nav id="nav">
            <ul>
                <li><a href="index.php">Estoque</a></li>
                <li><a href="#">Contato</a></li>
            </ul>
            <button class="btn-menu" onclick="openSearch()">
                <img style="width: 70px; float:right" src="./images/search.png">
            </button>
<!--            <button class="btn-menu">
                <img style="width: 70px; float:right" src="./images/search.png">
            </button>-->
        </nav>
        <?php
    }

}
