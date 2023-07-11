FRAME.registerComponent('audioanalyser-beat-scale', {
  schema: {
    analyserEl: {type: 'selector'}
  },

  init: function () {
    var analyserEl = this.data.analyserEl || this.el;
    var el = this.el;

    analyserEl.addEventListener('audioanalyser-beat', function () {
      el.setAttribute('scale', {
        x: volume,
        y: volume,
        z: volume
      });
    });
  }
});