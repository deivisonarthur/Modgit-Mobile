
    <?php
    global $d;
    if (isset($d['scale'])) $scale = $d['scale'];
    else $scale = 1.0;
    if (isset($_COOKIE['scale'])) $scale = $_COOKIE['scale'];
    ?>
    <meta name="viewport" id="vport" content="width=device-width, initial-scale=<?php echo $scale; ?>; target-densityDpi=device-dpi" />
    <?php echo $this->getChildHtml('head') ?>
    <script type="text/javascript">
        if (<?php if (!isset($_COOKIE['breakloop'])) echo 'true'; else echo 'false'; ?>) {
            setCookie('breakloop',1,1);
            var width = $(window).width();
            if (width < 480 && <?php echo $scale; ?> >= 1.0) {
                var scale = roundNumber(width/480,2);
                setCookie('scale',scale,1);
                if (getCookie('breakloop')) location.reload();
            } else if (width >= 480 && <?php echo $scale;?> < 1.0) {
                var scale = 1.0;
                setCookie('scale',scale,1);
                if (getCookie('breakloop')) location.reload();
            }
        }
        <?php if (isset($_COOKIE['breakloop'])): ?>
        setCookie('breakloop',1,-1); // expire it
        <?php endif; ?>
    </script>