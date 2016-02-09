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

The most well known module is probably [redirect](https://www.drupal.org/project/redirect).
*Redirector* aims to be much more lightweight than *redirect* and to allow
wildcard patterns.

Another alternative is [match_redirect](https://www.drupal.org/project/match_redirect).
While *match_redirect* allows using wildcard patterns, it stores redirections using
entities. This introduces (in our opinion) an unnecesary bloat and
complexity.  
Also, *Redirect* allows to specify in a single redirection with
multiple origins to the same destination.  To match the redirections,
it uses the function *drupal_match_paths* from Drupal core, wich
matches all possible origins in a single pass, making it very performant.

*Redirector* aims to be easy, fast and lightweight. In fact, the magic is done in
only 6 lines :)
Ever wondered where a redirection comes from? *Redirector* will use
the `x-redirected-by` header to show itself.
