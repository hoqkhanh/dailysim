<div id="branding" class="clearfix">
    <?php print $breadcrumb; ?>
    <?php print render($title_prefix); ?>
    <?php if ($title): ?>
        <h1 class="page-title"><?php print $title; ?></h1>
    <?php endif; ?>
    <?php print render($title_suffix); ?>
    <?php print render($primary_local_tasks); ?>
</div>

<div id="page">
    <?php if ($secondary_local_tasks): ?>
        <div class="tabs-secondary clearfix"><?php print render($secondary_local_tasks); ?></div>
    <?php endif; ?>
    <div id="content" class="clearfix">
        <div class="element-invisible"><a id="main-content"></a></div>
        <?php if ($messages): ?>
            <div id="console" class="clearfix"><?php print $messages; ?></div>
        <?php endif; ?>
        <div id="import-alter" style="display:none" class="messages error"></div>
        <?php if ($page['help']): ?>
            <div id="help">
                <?php print render($page['help']); ?>
            </div>
        <?php endif; ?>
        <?php if ($action_links): ?>
            <ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
        <?php print render($page['content']); ?>
    </div>
    <?php
    if ((arg(1) != null || arg(1) != "") && (arg(2) == null || arg(2) == '')) {
        global $base_url;
        if (arg(1) == 'bk_careers_professional_jobs_import') {
            print '<input class="form-submit import-cta" type="submit" id="professional-import" value="Sync" />';
            print '<img class="loading" style="display:none;" width="40" height="40" src="' . $base_url . '/' . drupal_get_path("module", "bk_careers_jobs") . '/loading-blue.gif" />';
        }

        if (arg(1) == 'bk_careers_restaurant_form') {
            print '<input class="form-submit import-cta" type="submit" id="restaurant-import" value="Sync" />';
            print '<img class="loading" style="display:none;" width="40" height="40" src="' . $base_url . '/' . drupal_get_path("module", "bk_careers_jobs") . '/loading-blue.gif" />';
        } else {

        }
    }
    ?>
    <div id="footer">
        <?php print $feed_icons; ?>
    </div>

</div>

<?php if (arg(2) == null || arg(2) == '') : ?>
    <script type="text/javascript">
        jQuery(document).ready(function ($) {
            //hide the box to upload
            $("#edit-feeds").hide();


            if ($('#edit-submit').attr('disabled')) {
                $("#professional-import").hide();
            } else {
                $("#edit-submit").hide();
            }

            $(".import-cta").click(function () {
                var page = "";
                if ($(this).attr('id') == "professional-import") {
                    page = "professional-import-call";
                }
                else if ($(this).attr('id') == "restaurant-import") {
                    page = "restaurant-import-call";
                }
                else {
                }
                cta_impport(page);
            });

        });
        /*
         ***   Call to action func import handler
         */
        function cta_impport(page) {
            jQuery("#import-alter").hide();
            jQuery(".import-cta").attr('disabled', 'disabled');
            jQuery("img.loading").show();
            var url_site = Drupal.settings.basePath;
            jQuery.post(url_site + page,
                "json",
                function (data) {
                    var data_obj = jQuery.parseJSON(data);
                    if (data_obj.status == 1) {
                        jQuery("form#feeds-import-form").submit();
                    } else if (data_obj.status == 0) {
                        jQuery("#import-alter").html(data_obj.message).show();
                    } else {
                        jQuery("#import-alter").html('There is an unexpected error').show();
                    }
                    jQuery(".import-cta").removeAttr('disabled');
                    jQuery("img.loading").hide();
                }
            );
        }
    </script>
<?php endif ?>