(function ($) {

/**
 * Based on Drupal core's collapse.js.
 * Toggle the visibility of an ul contained in a parent li, using smooth animations.
 * A div preceding the ul will be made clickable and is required.
 */
Drupal.toggleLi = function (li) {
  var $li = $(li);
  if ($li.is('.collapsed')) {
    var $content = $('> ul', li).hide();
    $li
      .removeClass('collapsed')
      .trigger({ type: 'collapsed', value: false })
      .find('> div span.div-prefix').html(Drupal.t('Hide'));
      $li.find('> div a.li-title').html('-');
    $content.slideDown({
      duration: 'fast',
      easing: 'linear',
      complete: function () {
        li.animating = false;
      },
    });
  }
  else {
    $li.trigger({ type: 'collapsed', value: true });
    $('> ul', li).slideUp('fast', function () {
      $li
        .addClass('collapsed')
        .find('> div span.div-prefix').html(Drupal.t('Show'));
      $li.find('> div a.li-title').html('+');
      li.animating = false;
    });
  }
};

Drupal.behaviors.collapseli = {
  attach: function (context, settings) {
    // Attach to Better Exposed Filters tree
    $('ul.bef-tree li:has(ul)', context).once('collapseli', function () {
      var $li = $(this);

      // Turn the div into a clickable link.
      var $div = $('> div', this);

      $('<span class="div-prefix element-invisible"></span>')
        .append($li.hasClass('collapsed') ? Drupal.t('Show') : Drupal.t('Hide'))
        .prependTo($div)
        .after(' ');

      // .wrapInner() does not retain bound events.
      var $link = $('<a class="li-title" href="#">-</a>')
        .appendTo($div)
        .click(function () {
          var li = $li.get(0);
          // Don't animate multiple times.
          if (!li.animating) {
            li.animating = true;
            Drupal.toggleLi(li);
          }
          return false;
        });
      // Initially collapse all.
      Drupal.toggleLi($li.get(0));
    });
  }
};

})(jQuery);
