<?php
?>
<?php print render($page['header']); ?>

<div id="wrapper">
    <div id="container" class="clearfix">

        <div id="header">
            <div id="header-content">
                <div id="logo"><span class="top">Đại lý sim</span><span class="bottom">.com.vn</span></div>
                <div id="search-top">
                    <img src="<?php echo base_path().path_to_theme().'/images/logo.png';?>" />
                </div>
            </div>
        </div>

        <div id="center">
            <?php print theme('links__system_main_menu', array('links' => $main_menu, 'attributes' => array('id' => 'main-menu', 'class' => array('links', 'inline', 'clearfix')))); ?>
            <?php if ($tabs): ?><div id="tabs-wrapper" class="clearfix"><?php endif; ?>
                <?php print render($title_prefix); ?>
                <?php print render($title_suffix); ?>
                <?php if ($tabs): ?><?php print render($tabs); ?></div><?php endif; ?>
            <?php print render($tabs2); ?>
            <?php print $messages; ?>
            <?php print render($page['help']); ?>
            <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
            <div id="content">
                <?php if ($page['left']): ?>
                    <div id="sidebar-first" class="sidebar">
                        <?php print render($page['left']); ?>
                    </div>
                <?php endif; ?>
                <div class="main">
                    <div class="clearfix">
                        <?php print render($page['content']); ?>
                    </div>
                </div>
                <?php if ($page['right']): ?>
                    <div id="sidebar-second" class="sidebar">
                        <?php print render($page['right']); ?>
                    </div>
                <?php endif; ?>
                <?php print $feed_icons ?>
            </div>
            <div id="footer">
                <p class="left">Copyright 2015@ dailysim.com.vn</p>
                <p class="right">Hotline: 0995 888 999 </p>
            </div>
        </div> <!-- /.left-corner, /.right-corner, /#squeeze, /#center -->


    </div> <!-- /#container -->
</div> <!-- /#wrapper -->
