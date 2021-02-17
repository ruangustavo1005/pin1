
function abrirDetalhes(sPlaca) {
    var sPlacaCarro = sPlaca.id;
    var oSection = document.getElementById('main-section');
    var oBgModal = document.createElement('div');
    var oModal = document.createElement('div');
    
    oBgModal.setAttribute('class', 'bg-modal');
    oBgModal.id = 'modalManage';
    oModal.setAttribute('class', 'modal');
    oBgModal.appendChild(oModal);
    oSection.appendChild(oBgModal);
    
    createDetails(sPlacaCarro);
}
    
function closeDetails() {
    var oMain = document.getElementById('main-section');
    var oModal = document.getElementById('modalManage');
    
    if(oModal) {
        oMain.removeChild(oModal);
    }
}

function createDetails(sPlacaCarro) {
    $.ajax({
       type:'POST',
       url: 'http://localhost/pin1/estrutura/ajax.php',
       data: {
           controller: 'ControllerDetalhes',
           processo: 'getHtmlFromView',
           placa: sPlacaCarro
       },
       cache: false,
       dataType: 'html',
       success: function (oRes) {
           if(oRes) {
               $(".modal").html(oRes);
           }
       }
    });
}