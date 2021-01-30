<!DOCTYPE html>
<html>
    <head>
        <meta charset="windows-1252">
        <title></title>
    </head>
    <body>
        <?php
        $oTag = new Estrutura\Tag('div', 'teste');
        $oTag->addAtributo('border', '1');
        echo $oTag->getHtml();
        ?>
    </body>
</html>