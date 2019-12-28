#define FFI_LIB "/usr/lib/x86_64-linux-gnu/libgtk-3.so"



typedef struct _GtkWidget GtkWidget;
typedef struct _GtkWindow GtkWindow;

typedef void* gpointer;
typedef char gchar;
typedef bool gboolean;
typedef unsigned long gulong;
typedef int gint;
typedef unsigned int guint;
typedef signed char gint8;
typedef signed char guint8;
typedef signed short guint16;
typedef unsigned int guint32;
typedef unsigned long gulong;
typedef double gdouble;
typedef gulong GType;

typedef struct {
  gint x;
  gint y;
  gint width;
  gint height;
} GtkAllocation;

// typedef void  (*GCallback)              (gpointer *widget, GdkEvent *data);

/**
 * https://www.cs.tut.fi/lintula/manual/gtk/gtk/gtk-standard-enumerations.html#GTKWINDOWPOSITION
 * https://lazka.github.io/pgi-docs/Gtk-3.0/enums.html
 *
 */
typedef enum
{
  GTK_WINDOW_TOPLEVEL,
  GTK_WINDOW_POPUP
} GtkWindowType;

typedef enum
{
  GTK_WIN_POS_NONE,
  GTK_WIN_POS_CENTER,
  GTK_WIN_POS_MOUSE
} GtkWindowPosition;


// GTK
void gtk_init(int *, char **[]);
void gtk_main();
void gtk_main_quit();

// GTKENTRY
GtkWidget *gtk_entry_new ();

// GTKWINDOW
GtkWidget *gtk_window_new (GtkWindowType);
void gtk_window_set_title (GtkWindow *, const gchar *);
void gtk_window_get_title (GtkWindow *);
void gtk_window_set_resizable (GtkWindow *, gboolean);
gboolean gtk_window_get_resizable (GtkWindow *);
void gtk_window_set_modal (GtkWindow *, gboolean);
gboolean gtk_window_get_modal (GtkWindow *);
void gtk_window_set_default_size (GtkWindow *, gint, gint);
void gtk_window_get_default_size (GtkWindow *window, gint *width, gint *height);
void gtk_window_set_position (GtkWindow *, GtkWindowPosition);
void gtk_window_get_position (GtkWindow *window, gint *root_x, gint *root_y);
void gtk_window_set_transient_for (GtkWindow *, GtkWindow *);
void gtk_window_set_attached_to (GtkWindow *, GtkWidget *);
void gtk_window_set_destroy_with_parent (GtkWindow *, gboolean);
void gtk_window_set_hide_titlebar_when_maximized (GtkWindow *, gboolean);

// GTKWIDGET
GtkWidget *gtk_widget_new (GType, const gchar *, ...);
void gtk_widget_destroy (GtkWidget *);
gboolean gtk_widget_in_destruction (GtkWidget *);
void gtk_widget_destroyed (GtkWidget *, GtkWidget **);
void gtk_widget_unparent (GtkWidget *);
void gtk_widget_show (GtkWidget *);
void gtk_widget_show_now (GtkWidget *);
void gtk_widget_hide (GtkWidget *);
void gtk_widget_show_all (GtkWidget *);
void gtk_widget_map (GtkWidget *);
void gtk_widget_unmap (GtkWidget *);
void gtk_widget_realize (GtkWidget *);
void gtk_widget_queue_draw (GtkWidget *);
void gtk_widget_queue_resize (GtkWidget *);
void gtk_widget_queue_resize_no_redraw (GtkWidget *);
void gtk_widget_queue_allocate (GtkWidget *);
gint gtk_widget_get_scale_factor (GtkWidget *);
void gtk_widget_size_allocate (GtkWidget *, GtkAllocation *);

// GTKCONTAINER
typedef struct _GtkContainer GtkContainer;

void gtk_container_add (GtkContainer *container, GtkWidget *widget);



// GDK
typedef enum
{
  GDK_NOTHING		= -1,
  GDK_DELETE		= 0,
  GDK_DESTROY		= 1,
  GDK_EXPOSE		= 2,
  GDK_MOTION_NOTIFY	= 3,
  GDK_BUTTON_PRESS	= 4,
  GDK_2BUTTON_PRESS	= 5,
  GDK_3BUTTON_PRESS	= 6,
  GDK_BUTTON_RELEASE	= 7,
  GDK_KEY_PRESS		= 8,
  GDK_KEY_RELEASE	= 9,
  GDK_ENTER_NOTIFY	= 10,
  GDK_LEAVE_NOTIFY	= 11,
  GDK_FOCUS_CHANGE	= 12,
  GDK_CONFIGURE		= 13,
  GDK_MAP		= 14,
  GDK_UNMAP		= 15,
  GDK_PROPERTY_NOTIFY	= 16,
  GDK_SELECTION_CLEAR	= 17,
  GDK_SELECTION_REQUEST = 18,
  GDK_SELECTION_NOTIFY	= 19,
  GDK_PROXIMITY_IN	= 20,
  GDK_PROXIMITY_OUT	= 21,
  GDK_DRAG_ENTER        = 22,
  GDK_DRAG_LEAVE        = 23,
  GDK_DRAG_MOTION       = 24,
  GDK_DRAG_STATUS       = 25,
  GDK_DROP_START        = 26,
  GDK_DROP_FINISHED     = 27,
  GDK_CLIENT_EVENT	= 28,
  GDK_VISIBILITY_NOTIFY = 29,
  GDK_NO_EXPOSE		= 30,
  GDK_SCROLL            = 31,
  GDK_WINDOW_STATE      = 32,
  GDK_SETTING           = 33,
  GDK_OWNER_CHANGE      = 34,
  GDK_GRAB_BROKEN       = 35,
  GDK_DAMAGE            = 36
} GdkEventType;

typedef struct _GdkWindow GdkWindow;
typedef struct _GdkDevice GdkDevice;



// GdkEventButton
struct _GdkEventButton
{
  GdkEventType type;
  GdkWindow *window;
  gint8 send_event;
  guint32 time;
  gdouble x;
  gdouble y;
  gdouble *axes;
  guint state;
  guint button;
  GdkDevice *device;
  gdouble x_root, y_root;
} ;
typedef struct _GdkEventButton GdkEventButton;

// GdkEventKey
struct _GdkEventKey
{
  GdkEventType type;
  GdkWindow *window;
  gint8 send_event;
  guint32 time;
  guint state;
  guint keyval;
  guint16 hardware_keycode;
  guint16 key_scancode;
  guint8 group;
  guint is_modifier : 1;
};
typedef struct _GdkEventKey	    GdkEventKey;

// GdkEvent
struct _GdkEvent
{
  GdkEventButton	    button;
  GdkEventKey	    	key;
};
typedef struct _GdkEvent GdkEvent;

// G

typedef void  *GCallback (gpointer *widget, GdkEvent *data);

typedef enum
{
	G_CONNECT_AFTER	= 1 << 0,
	G_CONNECT_SWAPPED	= 1 << 1
} GConnectFlags;

gulong g_signal_connect_object (gpointer instance, const gchar *detailed_signal, GCallback c_handler, gpointer gobject, GConnectFlags connect_flags);

typedef struct {
	guint in_marshal;
	guint is_invalid;
} GClosure;

typedef void *GClosureNotify (gpointer data, GClosure *closure);

typedef enum {
	G_SIGNAL_RUN_FIRST = 1 << 0,
	G_SIGNAL_RUN_LAST = 1 << 1,
	G_SIGNAL_RUN_CLEANUP = 1 << 2,
	G_SIGNAL_NO_RECURSE = 1 << 3,
	G_SIGNAL_DETAILED = 1 << 4,
	G_SIGNAL_ACTION = 1 << 5,
	G_SIGNAL_NO_HOOKS = 1 << 6,
	G_SIGNAL_MUST_COLLECT = 1 << 7,
	G_SIGNAL_DEPRECATED   = 1 << 8
} GSignalFlags;

typedef struct
{
	guint		signal_id;
	const gchar  *signal_name;
	GType		itype;
	GSignalFlags signal_flags;
	GType		return_type; /* mangled with G_SIGNAL_TYPE_STATIC_SCOPE flag */
	guint		n_params;
	const GType  *param_types; /* mangled with G_SIGNAL_TYPE_STATIC_SCOPE flag */
} GSignalQuery;

typedef struct _GTypeClass {
    GType g_type;
} GTypeClass;

typedef struct _GTypeInstance {
    GTypeClass *g_class;
} GTypeInstance;


guint g_signal_lookup (const gchar *name, GType itype);
void g_signal_query (guint signal_id, GSignalQuery *query);
GClosure *g_cclosure_new_swap (GCallback callback_func, gpointer user_data, GClosureNotify destroy_data);
gulong g_signal_connect_closure (gpointer instance, const gchar *detailed_signal, GClosure *closure, gboolean after);


GType g_type_fundamental (GType type_id);
const gchar *g_type_name (GType type);