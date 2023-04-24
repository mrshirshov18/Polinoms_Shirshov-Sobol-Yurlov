

window.addEventListener("DOMContentLoaded", event => {
  console.log("DOM fully loaded and parsed")
  const themeButton = document.querySelector(".theme-button")
  const handleClick = () => {
   let flag1="on"
   let t=document.querySelector('.put1').value

    var pol1JS=document.querySelector('.put1').value
    var pol2JS=document.querySelector('.put2').value
    var polJS=document.querySelector('.put3').value
    /*document.querySelector('.in').innerHTML = pol2JS
    document.querySelector('.out').innerHTML = t
    document.querySelector('.inout').innerHTML =polJS*/
    let znak='0'
    let data1=document.querySelector('.newswitch1').value
    let data2=document.querySelector('.newswitch2').value
    let data3=document.querySelector('.newswitch3').value
    let data4=document.querySelector('.newswitch4').value
    if (document.querySelector('.newswitch1').checked){
        /*document.querySelector('.кнопка1').innerHTML = data1*/
        znak="+"
    }
    else {
        /*document.querySelector('.кнопка1').innerHTML = ''*/
    }
    if (document.querySelector('.newswitch2').checked){
        /*document.querySelector('.кнопка2').innerHTML = data2*/
        znak="-"
    }
    else {
        /*document.querySelector('.кнопка2').innerHTML = ''*/
    }
    if (document.querySelector('.newswitch3').checked){
        /*document.querySelector('.кнопка3').innerHTML = data3*/
        znak="*"
    }
    else {
        /*document.querySelector('.кнопка3').innerHTML = ''*/
    }
    if (document.querySelector('.newswitch4').checked){
        /*document.querySelector('.кнопка4').innerHTML = data4*/
        znak="/"
    }
    else {
        /*document.querySelector('.кнопка4').innerHTML = ''*/
    }
    eel.send(pol1JS, pol2JS, znak, flag1)(try_to_send)
  }


  themeButton.addEventListener("click", handleClick);
})

window.addEventListener("DOMContentLoaded", event => {
  console.log("DOM fully loaded and parsed")
  const themeButton = document.querySelector(".theme-button1")
  const handleClick = () => {
    let flag2="on"
    var polJS=document.querySelector('.put3').value
    var Kor1=document.querySelector('.put4').value
    var Kor2=document.querySelector('.put5').value
    var Kor3=document.querySelector('.put6').value
    var constanta=document.querySelector('.put7').value
    /*document.querySelector('.inout').innerHTML =polJS
    document.querySelector('.икс').innerHTML =Kor1
    document.querySelector('.игрек').innerHTML =Kor2
    document.querySelector('.зед').innerHTML =Kor3
    document.querySelector('.константа').innerHTML =constanta*/
    eel.send1(polJS,Kor1,Kor2,Kor3,constanta,flag2)(try_to_send)
  }

  themeButton.addEventListener("click", handleClick);
})

window.addEventListener("DOMContentLoaded", event => {
  console.log("DOM fully loaded and parsed")
  const themeButton = document.querySelector(".theme-button3")
  const handleClick = () => {
    let flag3="on"
    var new_pol_js='X+Y'
    var name_pol_js='POL1'
    let radio= document.querySelectorAll('.i-7');
    for (let i=0;i<radio.length;i++){
        if (radio[i].checked){
            data=radio[i].value;
            break;
        }
    }
    /*document.querySelector('.name').innerHTML =data*/;
    var tablitsa = data;

    eel.send2(new_pol_js,name_pol_js,tablitsa,flag3)(try_to_send)
  }

  themeButton.addEventListener("click", handleClick);
})



const max = 1;
document.addEventListener('change', function(e) {
  if (e.target.tagName == 'INPUT') {
    if (document.querySelectorAll(".btn-group-toggle input[type='checkbox']:checked").length > max) {
      e.target.checked = false;
      console.log(`${max} buttons are alraedy checked!`);
    }
  }
});

window.addEventListener("DOMContentLoaded", event => {
  console.log("DOM fully loaded and parsed")
  const themeButton = document.querySelector(".theme-button2")
  const handleClick = () => {
    let flag4="on"
    var new_pol_js=document.querySelector('.put8').value
    var name_pol_js=document.querySelector('.put9').value
    let radio= document.querySelectorAll('.i-7');
    for (let i=0;i<radio.length;i++){
        if (radio[i].checked){
            data=radio[i].value;
            break;
        }
    }
    /*document.querySelector('.name').innerHTML =data*/;
    var tablitsa = data;

    eel.send3(new_pol_js,name_pol_js,tablitsa,flag4)(try_to_send)
  }

  themeButton.addEventListener("click", handleClick);
})



