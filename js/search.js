function onLoad() {
    document.getElementById('marca').style.display = 'block';
    document.getElementById('modelo').style.display = 'none';
}

function alterOption() {
    var oSelect   = document.getElementById('option'),
        sSelected = oSelect.options[oSelect.selectedIndex].value;
    
    if(sSelected === 'marca') {
        document.getElementById('marca').style.display = 'block';
        document.getElementById('modelo').style.display = 'none';
    } else {
        document.getElementById('modelo').style.display = 'block';
        document.getElementById('marca').style.display = 'none';
    }

}

function search() {
    var oSelect   = document.getElementById('option'),
        sSelected = oSelect.options[oSelect.selectedIndex].value;
    if(sSelected === 'marca') {
        var oMarca = document.getElementById('marca'),
            iSelected = oMarca.options[oMarca.selectedIndex].value;
    } else {
        var oModelo = document.getElementById('modelo'),
            iSelected = oModelo.options[oModelo.selectedIndex].value;
    }
    
    $.ajax({
       type:'POST',
       url: 'http://localhost/pin1/estrutura/ajax.php',
       data: {
           controller: 'ControllerEstoque',
           processo: 'getHtmlFromViewFiltrada',
           filter: sSelected,
           filterValue: iSelected
       },
       cache: false,
       dataType: 'html',
       success: function (oRes) {
           if(oRes) {
               debugger;
               $(".area-veiculos").html('');
               $(".area-veiculos").html(oRes);
               
           }
       }
    });
    
}

//window.addEventListener('load', onLoad);