use winit;
use winit::window::WindowAttributes;

#[derive(Default)]
struct ThyhappyApp {
    window: Option<winit::window::Window>,
}

impl winit::application::ApplicationHandler for ThyhappyApp {
    fn resumed(&mut self, event_loop: &winit::event_loop::ActiveEventLoop) {
        // Check if the window is already created
        if self.window.is_none() {
            // Create window
            self.window = Some(
                event_loop.create_window(
                    WindowAttributes::default()
                        .with_title("hello"))
                    .unwrap()
            )
        }
    }

    fn window_event(&mut self, event_loop: &winit::event_loop::ActiveEventLoop,
                    id:winit::window::WindowId,event:winit::event::WindowEvent) {
        // Window messages loop
        match event{
            winit::event::WindowEvent::CloseRequested => {
                event_loop.exit();
            }

            // Default
            _=>{}
        }
    }
}

pub fn thyhappy_gui_run() {
    let event_loop = winit::event_loop::EventLoop::new();
    let mut app = ThyhappyApp::default();
    event_loop.unwrap().run_app(&mut app).unwrap()
}