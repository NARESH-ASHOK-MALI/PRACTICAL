const burger = document.querySelector('.burger');
const navlinks = document.querySelector('nav ul');

burger.addEventListener('click', function(){
    navlinks.classList.toggle('active');
})