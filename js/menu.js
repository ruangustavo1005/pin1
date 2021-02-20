var bOpened = false;

function openSearch() {
    var oSection = document.getElementById('nav');
    if(!bOpened) {
        var oDiv = document.createElement('div');
        oDiv.setAttribute('class', 'search-div');
        oDiv.setAttribute('id', 'search-div');
        oSection.appendChild(oDiv);
        this.loadSearch();
    } else {
        var oDiv = document.getElementById('search-div');
        oSection.removeChild(oDiv);
    }
    bOpened = !bOpened;
}

function loadSearch() {
    $.ajax({
       type: 'POST',
       url: 'http://localhost/pin1/estrutura/ajax.php',
       data: {
           controller: 'ControllerMenu',
           processo: 'getHtmlSearch'
       },
       cache: false,
       dataType: 'html',
       success: function (oRes) {
           if(oRes) {
               $(".search-div").html(oRes);
                onLoad();
           }
       }
    });
}