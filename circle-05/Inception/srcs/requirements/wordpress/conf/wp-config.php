<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the web site, you can copy this file to "wp-config.php"
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// https://github.com/rhubarbgroup/redis-cache/wiki/Connection-Parameters

// ** Redis settings - You can get this info from your web host ** //

/** Redis hostname */
define( 'WP_REDIS_HOST', getenv('REDIS_HOST') );

/** Redis port */
define( 'WP_REDIS_PORT', getenv('REDIS_PORT') );

/** The timeout seconds for connection on redis */
define( 'WP_REDIS_TIMEOUT', getenv('REDIS_CONNECTION_TIMEOUT_SECONDS') );

/** The timeout seconds for read on redis */
define( 'WP_REDIS_READ_TIMEOUT', getenv('REDIS_READ_TIMEOUT_SECONDS') );

/** The logical database index on redis */
define( 'WP_REDIS_DATABASE', getenv('REDIS_DB_INDEX') );

/** True if do caching */
define( 'WP_CACHE', true );

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', getenv('MARIADB_DB') );

/** MySQL database username */
define( 'DB_USER', getenv('MARIADB_USER') );

/** MySQL database password */
define( 'DB_PASSWORD', getenv('MARIADB_PWD') );

/** MySQL hostname */
define( 'DB_HOST', getenv('MARIADB_HOST') );

/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication unique keys and salts.
 *
 * Change these to different unique phrases! You can generate these using
 * the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
 *
 * You can change these at any point in time to invalidate all existing cookies.
 * This will force all users to have to log in again.
 *
 * @since 2.6.0
 */

/**#@-*/
/* insert keys here */
define('AUTH_KEY',         'vvH6]0o-mIp6>%nG^lLJlg9n{!p<|xG,@z24zNvkfR3^dNJ9-t%/yv@wvG5wsNO-');
define('SECURE_AUTH_KEY',  '4t|wLj6Sui[,$|]TW!2rn;rQ^h8+Ajme.1_)I_=UV -CbAC8TUx+:/%gKwYabkB[');
define('LOGGED_IN_KEY',    ']@LxE tWIAG*6M2]<.l{GP/n*`K<M`i&##W%R3A|jwRira@Uw0W]>qK>J;??~Km ');
define('NONCE_KEY',        '%z0Ic0tu_7Tt7-(7De0c&QG%p`kK^$66Qd<6]F+9M81U!GD@*]kWS}h< :kv3|%+');
define('AUTH_SALT',        'y|Tp&Ofj3R43QAoag=M3#c>v >a5uwmw9+pAU&E;:ya4w.vVJE2se8i~/kW`fo,s');
define('SECURE_AUTH_SALT', '8kU[rC>.MKQT)hQnmohl_9+bA*+Dhbw6kdXSEn*J?027;%*FrpHdD-1i%J[`aTU&');
define('LOGGED_IN_SALT',   'JJ@G$j{lXDRX!`)8S|:6tCRolFWNEN3qysEWy1K.kfc2=tfV>YdgFW.8HyOC|+=o');
define('NONCE_SALT',       '[Sex%,Ln+R}mxRxguAns|mo`Bjk%P]i#mv%sEW)}KxX3J`s(`s:a|Lb5*i4^k(Z`');

/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* Add any custom values between this line and the "stop editing" line. */



/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
        define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
