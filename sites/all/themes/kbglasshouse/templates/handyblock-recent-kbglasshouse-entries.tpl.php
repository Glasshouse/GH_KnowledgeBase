<?php if (!empty($nodes)) : ?>
<ul class="<?php print $classes; ?>">
<?php foreach ($nodes as $node) : ?>
<li><?php print l($node['title'], $node['url']); ?></li>
<?php endforeach; ?>
</ul>
<?php endif; ?>