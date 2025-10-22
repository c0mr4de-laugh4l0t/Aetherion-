// 3D tilt effect on hero section based on mouse movement
const hero = document.getElementById('hero');
const heroContent = document.querySelector('.hero-content');

hero.addEventListener('mousemove', (e) => {
  const x = (window.innerWidth / 2 - e.pageX) / 25;
  const y = (window.innerHeight / 2 - e.pageY) / 25;
  heroContent.style.transform = `rotateY(${x}deg) rotateX(${y}deg)`;
});

hero.addEventListener('mouseleave', () => {
  heroContent.style.transform = 'rotateY(0deg) rotateX(0deg)';
});

// Scroll reveal effect for sections
const sections = document.querySelectorAll('section');

function revealOnScroll() {
  const triggerBottom = window.innerHeight * 0.8;

  sections.forEach(section => {
    const sectionTop = section.getBoundingClientRect().top;
    if (sectionTop < triggerBottom) {
      section.classList.add('visible');
    }
  });
}

window.addEventListener('scroll', revealOnScroll);
revealOnScroll(); // Initial check

// Prevent default form submit for now (demo)
document.querySelector('form').addEventListener('submit', e => {
  e.preventDefault();
  alert('Thank you for subscribing!');
});
