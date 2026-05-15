use winit::window::Window;
use std::sync::Arc;
use wgpu;

struct ThyhappyGUIRenderer {
        window: Arc<Window>,
        device: wgpu::Device,
        queue: wgpu::Queue,
        surface: wgpu::Surface<'static>,
        config: wgpu::SurfaceConfiguration,
        size: winit::dpi::PhysicalSize<u32>,
        size_changed: bool,
}

pub fn initialize(){
        todo!()
}

impl ThyhappyGUIRenderer {
        async fn new(window: Arc<Window>) -> Self {
                // Create wgpu instance
                let instance = wgpu::Instance::new(
                        wgpu::InstanceDescriptor {
                                backends: wgpu::Backends::all(),
                                ..Default::default()
                        }
                );

                // Create surface
                let surface = instance.create_surface(window.clone()).unwrap();

                // Create adapter instance
                let adapter = instance.request_adapter(
                        &wgpu::RequestAdapterOptions{
                                power_preference : wgpu::PowerPreference::HighPerformance,
                                compatible_surface : Some(&surface),
                                force_fallback_adapter : false,
                        }
                ).await.unwrap();

                // Create logical devices and commands queue
                let (device, queue) = adapter.request_device(
                        &wgpu::DeviceDescriptor{
                                label: Default::default(),
                                required_features: wgpu::Features::empty(),
                                required_limits: Default::default(),
                        }
                        ,Default::default()
                ).await.unwrap();

                let cap = surface.get_capabilities(&adapter);

                // Set size
                let mut size = window.inner_size();

                // Check if the window size is safe
                size.width  = size.width. max(1);
                size.height = size.height.max(1);

                // Set the configuration
                let config = wgpu::SurfaceConfiguration{
                        usage: wgpu::TextureUsages::RENDER_ATTACHMENT,
                        format: cap.formats[0],
                        width: size.width,
                        height: size.height,
                        present_mode: wgpu::PresentMode::Fifo,
                        desired_maximum_frame_latency: 2,
                        alpha_mode: cap.alpha_modes[0],
                        view_formats: vec![],
                };

                surface.configure(&device, &config);

                Self{
                        window,
                        device,
                        queue,
                        surface,
                        config,
                        size,
                        size_changed: false,
                }
        }
}