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

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', getenv('MARIADB_DB') );

/** MySQL database username */
define( 'DB_USER', getenv('MARIADB_USER') );

/** MySQL database password */
define( 'DB_PASSWORD', getenv('MARIADB_PWD') );

/** MySQL hostname */
define( 'DB_HOST', getenv('MARIADB_HOST') ); #. ':' . getenv('MARIADB_PORT') );

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
define('AUTH_KEY',         '7(#v_+bP}-aL}HW8Nj0<,veKy/ZO=_#7%7(F@Fu7+#WEomrFK4^ix`yCc0kR2r:<');
define('SECURE_AUTH_KEY',  'x6V-*ygqC9=xPV.)UtI0Fy(XA-D*^Yv{@u%jrvzi|d;xDyLkA9A[xlLOF.i?E.*$');
define('LOGGED_IN_KEY',    'niC`K>$u)fDDwrVtLSr LD]Q~Zn<$^UAs}9g_W-~.-e0u5^Z6|6LN_UZty>^%)C}');
define('NONCE_KEY',        '&Bk:pMOP{ @^wqpP5+w+xMv7-AM;oEWj*-Jx74dWAHIm^GFpmw$WMx+7/Yr@Z@{A');
define('AUTH_SALT',        '}1:L1VIYPBt_>Nl}L$t{Y~y%PLjy!3l7DkP2swuLHR$qrnVO_oeTAat6R lfGY.<');
define('SECURE_AUTH_SALT', 'N Cboj#n|2bxZ`7&%[z$_Xz2XBrHmxRH}5kGPY(-qN+f_cx1ae8F~L8C>jj{3+%G');
define('LOGGED_IN_SALT',   'm-`3)e:tk<[eN>!]gIHpS!/,@eZ37^6JDsn`2&-z-[8C5H7EY pO}FeRe0Qt6D-c');
define('NONCE_SALT',       '=[r)8zy4IuQxG,xhv|j(^3]*]A.%_cC)YYm)FP31Mlu`=2ISY-5[6/?@]{kwqvk8');

/**#@-*/

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
