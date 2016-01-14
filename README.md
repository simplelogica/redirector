# redirector

*Redirector* allows you to manage redirections from inside Drupal.

## How to use

To use *Redirector*:

1. Clone this repo inside your *modules* folder
2. Enable the module (`drush en -y redirector`)
3. Clear cache (`drush cc all`)
4. Load the path (`admin/config/search/redirector`) in your browser
5. Create, edit or delete redirections

## Why another module?

Currently, various redirection modules exist for Drupal 7.

The most well known module is probably [redirect](https://www.drupal.org/project/redirect)*
*Redirector* aims to be much more lightweight than *redirect* and to allow
wildcard patterns.

Another alternative is [match_redirect](https://www.drupal.org/project/match_redirect).
While *match_redirect* allows using wildcard patterns, it stores redirections using
entities. This introduces (in our opinion) an unnecesary bloat and complexity.

*Redirector* aims to be easy, fast and lightweight. In fact, the magic is done in
only 6 lines :)
