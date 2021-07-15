function validateForm(e) {
    e.preventDefault();
    var name = document.loginForm.name.value;
    var password = document.loginForm.password.value;
   if (name.length==0)
    return alert(`name is required`);
   if (password.length<5)
    return alert(`password length should more than 5`);
   }
   
//  function heart(){
//   var c = document.getElementById("heart");
//   var ctx = c.getContext("2d");
//   ctx.fillStyle = "#FF0000";
//   ctx.fillRect(20, 20, 150, 100);
//  } 
// (function() {
//     const heart = document.getElementById('heartt');
//     heart.addEventListener('click', function() {
//       heart.classList.toggle('red');
//     });
//   })();
function h(id) {
  const heart = document.getElementById(id);
  heart.addEventListener('click',heart.classList.toggle('red'));
  }
//   function c() {
//     const clr=document.getElementById('clr');
//     clr.addEventListener('click',clr.nextAll(':not(:lat-child)').remove());
// };

