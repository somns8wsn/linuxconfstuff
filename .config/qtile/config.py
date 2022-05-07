from libqtile import bar, layout, widget, hook
from libqtile.config import Click, Drag, Group, Key, Match, Screen
from libqtile.lazy import lazy


def push_window(direction):
    def callback(qtile):
        x = qtile.groups.index(qtile.current_group)
        group_l = qtile.groups[x - 1].name
        group_r = qtile.groups[x + 1].name
        current = qtile.current_window
        last_name = qtile.groups[len(qtile.groups) - 2].name
        first_name = qtile.groups[0].name


        if direction == "left":
            if current and x > 0:
                current.togroup(group_l, switch_group = True)
            else:
                current.togroup(last_name, switch_group = True)

        elif direction == "right":
            if current and x < len(qtile.groups) - 2:
                current.togroup(group_r, switch_group = True)
            else:
                current.togroup(first_name, switch_group = True)

    return callback

mod = "mod4"
terminal = "kitty"

keys = [
    Key([mod], "h", lazy.layout.left()),
    Key([mod], "l", lazy.layout.right()),
    Key([mod], "j", lazy.layout.down()),
    Key([mod], "k", lazy.layout.up()),

    Key([], "F8", lazy.spawn("amixer -D default -q set Capture toggle")),

    Key([mod, "mod1"], "l", lazy.screen.next_group()),
    Key([mod, "mod1"], "h", lazy.screen.prev_group()),

    Key([mod], "Right", lazy.screen.next_group()),
    Key([mod], "Left", lazy.screen.prev_group()),

    Key([mod, "shift"], "h", lazy.layout.shuffle_left()),
    Key([mod, "shift"], "l", lazy.layout.shuffle_right()),
    Key([mod, "shift"], "j", lazy.layout.shuffle_down()),
    Key([mod, "shift"], "k", lazy.layout.shuffle_up()),

    Key([mod, "control"], "h", lazy.layout.grow_left()),
    Key([mod, "control"], "l", lazy.layout.grow_right()),
    Key([mod, "control"], "j", lazy.layout.grow_down()),
    Key([mod, "control"], "k", lazy.layout.grow_up()),
    Key([mod], "n", lazy.layout.normalize()),

    Key([mod], "s", lazy.layout.toggle_split()),
    Key([mod], "Return", lazy.spawn(terminal)),
    Key([mod], "Tab", lazy.next_layout()),
    Key([mod, "shift"], "c", lazy.window.kill()),
    Key([mod, "control"], "r", lazy.reload_config()),
    Key([mod, "control"], "q", lazy.shutdown()),

    Key([mod, "shift"], "Return", lazy.spawn("rofi -show run")),
    Key([mod, "control"], "Print", lazy.spawn("scrot -fsq100")),
    Key([mod], "Print", lazy.spawn("scrot -q100")),
    Key([mod], "u", lazy.window.toggle_floating()),
    Key([mod], "f", lazy.window.toggle_fullscreen()),
    Key([mod, "shift"], "Left", lazy.function(push_window("left"))),
    Key([mod, "shift"], "Right", lazy.function(push_window("right"))),
]

groups = [Group(i) for i in "1234567890"]

for i in groups:
    keys.extend(
        [
            Key([mod], i.name, lazy.group[i.name].toscreen()),
            Key([mod, "shift"], i.name, lazy.window.togroup(i.name, switch_group=True)),
        ]
    )

layouts = [
    layout.Columns( border_focus='8ec07c',
                    border_focus_stack='d3869b',
                    border_normal='30432a',
                    border_normal_stack='422a31',
                    border_width=1,
                    margin=1,
                    grow_amount=2,
                    insert_position=1,
                    ),
    layout.Max(),
]

widget_defaults = dict(
    font='serif',
    fontsize=14,
    padding=0,
    background='1d2021',
    foreground='ebdbb2',

)
extension_defaults = widget_defaults.copy()

screens = [
    Screen(
        top=bar.Bar(
            [

                widget.Spacer(length=40),

                widget.GroupBox(
                    active='ebdbb2',
                    borderwidth=2,
                    disable_drag=True,
                    highlight_color=['1d2021', '928374'],
                    highlight_method='line',
                    inactive='504945',
                    margin=1,
                    other_current_screen_border='427b58',
                    other_screen_border='427b58',
                    padding=1,
                    rounded=False,
                    this_current_screen_border='427b58',
                    this_screen_border='427b58',
                    urgent_alert_method='block',
                    urgent_border='8ec07c',
                    urgent_text='ebdbb2',
                    use_mouse_wheel=False,
                    ),

                widget.Spacer(length=10),

                widget.CurrentLayoutIcon(
                    scale=0.6,
                    ),

                widget.Spacer(),

                widget.WindowName(
                   max_chars=30,
                   font='sans',
                   foreground='928374',
                   ),

                widget.Spacer(),

                widget.Net(
                    format='{total} ⮃',
                    prefix='k',
                    update_interval=3,
                    font='mono bold',
                    fontsize=14,
                    foreground='b8bb26',
                    ),

                widget.Sep(padding=80, size_percent=45, foreground='a89984'),

                widget.DF(
                    format='+{uf}{m} 🖴',
                    partition='/home',
                    visible_on_warn=False,
                    font='mono bold',
                    fontsize=14,
                   foreground='fabd2f',
                    ),

                widget.Sep(padding=80, size_percent=45, foreground='a89984'),

                widget.CPU(
                    format='{load_percent}% 閭',
                    update_interval=3.0,
                    font='mono bold',
                    fontsize=14,
                    foreground='83a598',
                    ),

                widget.Sep(padding=80, size_percent=45, foreground='a89984'),

                widget.Memory(
                    format='{MemUsed:.2f}{mm} ',
                    measure_mem='G',
                    font='mono bold',
                    fontsize=14,
                    foreground='d3869b',
                    ),

                widget.Sep(padding=80, size_percent=45, foreground='a89984'),

                widget.TextBox(text='', fontsize=45, foreground='928374'),
                widget.TextBox(text='', fontsize=45, foreground='cc241d'),

                widget.Spacer(),

                widget.Volume(
                    padding=0,
                    cardid=0,
                    emoji=True,
                    fontsize=16,
                    step=0,
                    channel='Capture',
                    ),

                widget.Spacer(length=10),

                widget.Clock(format="%d %b(%a), %H:%M"),

                widget.Spacer(length=10),

                widget.Systray(),

                widget.Spacer(length=40),
            ],
            22,
        ),
        wallpaper="~/background/background.png",
        wallpaper_mode="fill",
    ),
]


# Drag floating layouts.
mouse = [
    Drag([mod], "Button1", lazy.window.set_position_floating(), start=lazy.window.get_position()),
    Drag([mod], "Button3", lazy.window.set_size_floating(), start=lazy.window.get_size()),
]

dgroups_key_binder = None
dgroups_app_rules = []  # type: list
follow_mouse_focus = True
bring_front_click = False
cursor_warp = False
floating_layout = layout.Floating(
    border_focus='cc241d',
    border_mormal='440c09',
    float_rules=[
        # Run the utility of `xprop` to see the wm class and name of an X client.
        *layout.Floating.default_float_rules,
        Match(wm_class="confirmreset"),
        Match(wm_class="makebranch"),
        Match(wm_class="maketag"),
        Match(wm_class="ssh-askpass"),
        Match(title="branchdialog"),
        Match(title="pinentry"),
        Match(wm_class="mumble"),
        Match(wm_class="keepass2"),
        Match(title="Friends List")
    ]
)
auto_fullscreen = True
focus_on_window_activation = "smart"
reconfigure_screens = True

# If things like steam games want to auto-minimize themselves when losing focus, should we respect this or not?
auto_minimize = True

# When using the Wayland backend, this can be used to configure input devices.
wl_input_rules = None

wmname = "LG3D"

@hook.subscribe.client_new
def throw_to_group(client):
    if client.name == "Mozilla Firefox":
        client.togroup("2")

    elif client.name == ("Discord"):
        client.togroup("3")

    elif client.name == "Telegram":
        client.togroup("4")

    elif client.name == "Steam":
        client.togroup("5")
