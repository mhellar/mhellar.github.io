AFRAME.registerComponent('circle', {
  schema: {
      amount: {
          type: 'number',
          default: 10
      },
      color: {
          type: 'color',
          default: 'red'
      },
      duration: {
          type: 'number',
          default: 10000
      },
      randScaleMax: {
          type: 'number',
          default: 3
      },
  },
  //custom function
  getRandomInt: function (min, max) {
      min = Math.ceil(min);
      max = Math.floor(max);
      return Math.floor(Math.random() * (max - min)) + min; //The maximum is exclusive and the minimum is inclusive
  },
  getRandomColor: function () {
      var letters = '0123456789ABCDEF'.split('');
      var color = '#';
      for (var i = 0; i < 6; i++) {
          color += letters[Math.floor(Math.random() * 16)];
      }
      return color;
  },
  init: function () {
      var box = document.createElement('a-sphere');
      box.setAttribute('shader-frog', "src:url(https://raw.githubusercontent.com/mhellar/aframestuff/gh-pages/basic4/shaders/Acid_Glow_Shader.json)")
      box.setAttribute('position', 0 + ' ' + 6 + ' ' + 10);
      box.setAttribute('scale', '180 180 180');
      this.el.appendChild(box);
  }
});
