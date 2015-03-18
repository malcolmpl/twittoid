The Twittoid will be divided in some big components.

**Please edit this section if whatever is wrong. I've never been using twitter so you know this system better.**



# UI #
  * Technologies: Plasma and Plexy (both independent UIs).

Here we should be able to select if we can see all messages for all TL¹ or for one specific. It would be like a filter.
The same about posting a new message. We should be able to post it to a specific TL or to all TL's.
It will show like kdetwitter our followings' pictures and our picture near the post form.

¹I mean TL (Twitter Like) as for those different microblogging webpages: Twitter, Jisko, Blip, etc.


---

# SingletonEngine #
  * Technologies: QT
It is the main part of Twittoid. It's made up of these parts above:

## AbstractServices ##
This superclass will provide services for the different types of webservices we have nowadays (Microblogging, Pictures, Online Calendars...).
> ### PluginLoader (Microblog) ###
> This will be the interface through we will be able to use plugins. Microblog will be the only class which manages Plugins, so another classes won't have direct access to plugins.

## Item ##
Item describes parsed data which the Engine sends to UI.

![http://www.airsoftvalley.com/i/item.png](http://www.airsoftvalley.com/i/item.png)


## ConfigurationStorage ##
  * Save all/selected ConfigItem.
  * Load all/selected ConfigItem.


## ConfigItem ##
![http://www.airsoftvalley.com/i/configitem.png](http://www.airsoftvalley.com/i/configitem.png)


## ConnectionManager ##
  * Connects to website.
  * Returns unparsed data.

## Custom Events system ##
We need also that system to exchange beetwen plugins and engine.
(in progress :)

## UI+Engine diagram ##
![http://www.airsoftvalley.com/i/diagram.png](http://www.airsoftvalley.com/i/diagram.png)


---

# Config #
  * Technologies: QT

It has it's own UI. Maybe similar like Kopete for adding new TL's.
Config will be stored through ConfigStorage.

TODO: How do we store encrypted passwords?