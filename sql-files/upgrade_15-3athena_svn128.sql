ALTER TABLE `cart_inventory` MODIFY `equip` int(11) unsigned NOT NULL default '0';
ALTER TABLE `guild_storage` MODIFY `equip` int(11) unsigned NOT NULL default '0';
ALTER TABLE `inventory` MODIFY `equip` int(11) unsigned NOT NULL default '0';
ALTER TABLE `storage` MODIFY `equip` int(11) unsigned NOT NULL default '0';
ALTER TABLE `mail` ADD `bound` TINYINT( 1 ) UNSIGNED NOT NULL DEFAULT '0';
